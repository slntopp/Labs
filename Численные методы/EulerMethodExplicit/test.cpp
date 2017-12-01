#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
using namespace std;
const int n = 3;

double f1(double* u,double a,double k);
double f2(double* u,double a,double k);
double f3(double* u,double a,double k);
void FN(double *uk1,double *uk, double Tau,double a,double k,double*Fn);
void Metod_Nutona(double* x,double *yk, double Tau,double a,double k,double*Fn);
void Yavnui_metod_Eilera(int n,double *yo,double a, double k);
void Neiavnui_metod_Eilera(double*u,double a,double k,double*Fn);
double* Metod_Gaussa(double **Jac,int n,double *dx);
bool out = true;

int main()
{
	double t = 0;
	double T = 1;
	double a = 1;
	double k = 2;
	double Eps = 0.001;
	double TauMax = 0.5;

	double*u = new double [n];
	double*Fn = new double [n];

	double **Jac;
	Jac = new double*[n];
	for ( int i=0;i<n;i++ )
		Jac[i]=new double[n+1];

	double*F;
	F = new double[n];

	double*dx;
	dx = new double [n];

	cout<<"Vvedite znachenia:"<<endl<<endl;

	for(int i =0; i<n;++i)
	{
		cout<<"u["<<i<<"] = ";
		cin>>u[i];
	}
	// cout<<"============================================================================"<<endl;
	// Yavnui_metod_Eilera(n,u,a,k);
	cout<<"============================================================================"<<endl;
	Neiavnui_metod_Eilera(u,a,k,Fn);
	return 0;
}

void Yavnui_metod_Eilera(int n,double *yo,double a, double k){
	cout<<"Yavnui Metod Eilera"<<endl;
	cout<<"============================================================================"<<endl;
	ofstream outf;
	outf.open("Yavnii metod Eilera.txt");

	double TauMax = 0.01,nit = 0,T=1,t = 0,Eps = 0.01;
	double TauMin;
	int d = 0;

	double*sh = new double [n];
	double*y = new double [n];
	double* f=new double[n];
		for(int i = 0;i<n;++i)
			y[i]=yo[i];

	cout<<setw(15)<<"k"<<setw(10)<<"t"<<setw(15)<<"F1"<<setw(15)<<"F2"<<setw(15)<<"F3"<<endl;
	cout<<"======================================================================="<<endl;
	while(t<T)	{
		f[0] = f1(y,a,k);
		f[1] = f2(y,a,k);
		f[2] = f3(y,a,k);
		for(int i = 0;i<n;++i)
			sh[i]= Eps/(fabs(f[i])+Eps/TauMax);

		if(sh[0]>sh[1])
			TauMin = sh[1];
		else
			if(TauMin > sh[2])
				TauMin = sh[2];


		for(int i =0; i<n; ++i)					//metod Eilera
			y[i] = y[i] + TauMin*f[i];
		if(t+TauMin>T)
		{
			t=T;
			TauMin=T-t;
		}

		t = t + TauMin;
		++d;
		outf<<t<<"          "<<y[0]<<"           "<<y[1]<<"           "<<y[2]<<"           "<<'\n';
		cout<<setw(15)<<d<<setw(15)<<t<<setw(15)<<sh[0]<<setw(15)<<sh[1]<<setw(15)<<sh[2]<<endl;
		nit++;

	}
	cout<<"============================================================================"<<endl;
	cout<<"iter = "<<nit<<endl;
	cout<<"Y1 = "<<y[0]<<endl;
	cout<<"Y2 = "<<y[1]<<endl;
	cout<<"Y3 = "<<y[2]<<endl;

	delete []sh;
	outf.close();
}

void Neiavnui_metod_Eilera(double*u,double a,double k,double*Fn)
{
	cout<<"Neyavnui Metod Eilera"<<endl;
	cout<<"============================================================================"<<endl;
	cout<<setw(15)<<"k"<<setw(15)<<"t"<<setw(15)<<"F1"<<setw(15)<<"F2"<<setw(15)<<"F3"<<endl;
	double Tau,Tau1,Tau_1,TauMax = 0.5;
	double t1=0,t=0;
	double T = 1,Eps = 0.01,TauMin = 0.01;
	double *yk = new double[n];
	double *yk1 = new double [n];
	double *yk_1 = new double[n];
	double *tau = new double[n];
	Tau=Tau_1=TauMin;
	int N = 0;
	for(int i = 0; i< n;++i)
		yk1[i]=yk[i]=yk_1[i]=u[i];

	ofstream outn;
	outn.open("Neyavnii metod Eilera.txt");


	double *Ek;
	Ek = new double [n];

	while(t<T)
	{
		t1 = t +Tau;
		Metod_Nutona(yk,yk1,Tau,a,k,Fn);
		for(int i =0;i<n;++i)
			Ek[i] = -((Tau/(Tau+Tau_1))*(yk1[i]-yk[i]-Tau/Tau_1*(yk[i]-yk_1[i])));
		bool r = false;
		for (int i =0; i<n;i++)
		{
			if(fabs(Ek[i])>Eps && (!r))
			{
				Tau/=2;
				Tau1 = Tau;
				for(int i = 0;i<n;++i)
					yk1[i]=yk[i];
				r = true;
			}
		}
		if(r)
			continue;
		for(int i = 0;i<n;++i)
			{
				/*if(fabs(Ek[i])>Eps)
					tau[i] = Tau/2;
				if (fabs(Ek[i])>Eps/4 && fabs(Ek[i])<=Eps)
					tau[i] = Tau;
				if (fabs(Ek[i])<=Eps/4)
					tau[i]=2*Tau;*/
				if(fabs(Ek[i])<Eps)
					tau[i] = sqrt(fabs(Eps/Ek[i]))*Tau;
			}

		Tau1 = tau[0];
		if(Tau1>tau[1])
			Tau1 = tau[1];
		if (Tau1 > tau[2])
			Tau1 = tau[2];

		if(Tau1>TauMax)
			Tau1= TauMax;
		cout<<setw(15)<<N<<setw(15)<<t<<setw(15)<<yk[0]<<setw(15)<<yk[1]<<setw(15)<<yk[2]<<endl;

		for( int i=0; i<n; i++)
		{
			yk_1[i]=yk[i];
			yk[i]=yk1[i];
		}
		Tau_1=Tau;
		Tau=Tau1;
		t=t1;
		N++;
		outn<<t<<"          "<<yk[0]<<"           "<<yk[1]<<"           "<<yk[2]<<"           "<<'\n';

	}
	cout<<"============================================================================"<<endl;
		cout<<"iter = "<<N<<endl;
		cout<<"Y1 = "<<yk[0]<<endl;
		cout<<"Y2 = "<<yk[1]<<endl;
		cout<<"Y3 = "<<yk[2]<<endl;
	outn.close();

	delete []yk;
	delete []yk1;
	delete []yk_1;
	delete []tau;
	delete []Ek;

}
void Metod_Nutona(double* x,double *yk,double Tau,double a,double k,double *Fn)
{
	int n = 3;
	FN(x,yk,Tau,a,k,Fn);

	double **Jf = new double*[n];
	for(int i=0; i<n; i++)
		Jf[i] = new double[n+1];

	double *dx = new double[n];
	double d1,d2;
	double e1=1e-4;
	double e2=1e-4;
	double eps = 1e-6;

		int iter = 1;
 do
 {
	for(  int i = 0; i<n; i++)
		Jf[i][n] = -Fn[i];

	for(int i = 0; i<n; i++ )
	{
		for(int j = 0; j<n; j++)
		{
			double f1,f2;
			x[j] += eps;
			FN(x,yk,Tau,a,k,Fn);
			f1 = Fn[i];								//	Jacobi

			x[j] -= eps;
			FN(x,yk,Tau,a,k,Fn);
			f2 = Fn[i];
			Jf[i][j] = (f1 - f2)/eps;
		}
	}

	Metod_Gaussa(Jf, n, dx);
	for( int i=0; i<n; i++)
		x[i]+=dx[i];

	d1 = fabs(Jf[0][n]);
	for(  int i=1; i<n; i++)
		if (fabs(Jf[i][n]) > d1)
			d1 = fabs(Jf[i][n]);

	if(fabs(x[0])<1)
		d2 = fabs(dx[0]);
	else
		d2 = fabs(dx[0]/x[0]);

	for(  int i=1; i<n; i++)
	{
		if (fabs(x[i]) < 1)
			if(d2 < fabs(dx[i]))
				d2 = fabs(dx[i]);
			else
				if (d2 < fabs(dx[i]/x[i]))
					d2 = fabs(dx[i]/x[i]);
	}
	iter++;
 }
 while ( d1>e1 || d2>e2);
}
double* Metod_Gaussa(double **Jac,int n,double *dx)
{
	//Pryamou xod Metoda Gaysa
	for(int i=0;i<n;i++)										//Poisk maximalnogo elementa(v pervom stolbike)
	{	      													//glavny element i stolbca
		double max = fabs(Jac[i][i]);							//perestanovka i stroki c naidenoi(pereprisvaivaem novera strok)
		int my = i;
		for(int t=i; t<n ;t++)
			if (fabs(Jac[t][i])>max)
			{
				max=fabs(Jac[t][i]);
				my=t;
			}
			//Peremes4enie strok
			if (my!=i)
			{
				double *per=Jac[i];
				Jac[i]=Jac[my];
				Jac[my]=per;
			}
			//delenie g stroki
			double amain=Jac[i][i];
			for(int z=0; z<n+1; z++)
			{
				Jac[i][z]=Jac[i][z]/amain;
			}

			//vychitanie iz i=1 i dalee strok i-y * na i-y koefficient sootvetstvuy stroki
			for(int j=i+1; j<n; j++)
			{
				double b = Jac[j][i];
				for(int z=i; z<n+1; z++)
					Jac[j][z]-=Jac[i][z]*b;
			}
		}
	//obratny hod gausa

	for(int i=n-1; i>0;i--)
	{
		for(int j=i-1;j>=0;j--)
				Jac[j][n]-=Jac[j][i]*Jac[i][n];
	}
	for(int i =0;i<n;++i)
		dx[i] =  Jac[i][n];
	if(out){
		cout << "### "<< dx[0] << " --------- " << Jac[0][0] << "####"<< endl;
		out = false;
	}
	return dx;
}
void FN(double *uk1,double *uk, double Tau,double a,double k,double*Fn)
{
	Fn[0] = uk1[0]-uk[0]-Tau*((k-a)/a*uk[1]*uk[2]);
	Fn[1] = uk1[1]-uk[1]-Tau*((a+k)/k*uk[2]*uk[0]);
	Fn[2] = uk1[2]-uk[2]-Tau*((a-k)/a*uk[0]*uk[1]);
}
double f1(double*u,double a,double k)
{
	return ((k-a)/a)*u[1]*u[2];
}
double f2(double*u,double a,double k)
{
	return ((a+k)/k)*u[0]*u[2];
}
double f3(double*u,double a,double k)
{
	return ((a-k)/a)*u[0]*u[1];
}
