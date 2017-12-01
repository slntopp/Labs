require 'pry'
require "../Метод Гаусса/art.rb"
require '../../include/gauss.rb'

#################################################
# =>                                            #
# =>           Система уравнений                #
# =>                                            #
#################################################
def func0(u, a, k)
  return ((k - a) / a) * u[1] * u[2]
end
def func1(u, a, k)
  return ((a + k) / k) * u[0] * u[2]
end
def func2(u, a, k)
  return ((a - k) / a) * u[0] * u[1]
end
#################################################

T, E = 1, 0.01

def EulerExplicit(u, a, k, out = false, round = false)
  tau_max, t, iter, step, f, a, k, dots = 0.01, 0, 0, [], [], a.to_f, k.to_f, []
  # Объявление переменных: максимальная погрешность, параметр, счетчик итераций цикла, шаг интегрирования,
  # массив значений функций, приведение типов a и k(нужно в Ruby для правильного выполнения мат. операций)
  u.map {|x| x.to_f} # Приведение типов значений начальных значений
  while t < T
    for i in 0..(u.size - 1) do
      f[i] = self.send("func#{i.to_s}", u, a, k)
      # Получение значений функций, обращение self.send(...) означает вызов функции
      # по названию переданному первым параметром в данной области видимости, с параметрами следующими далее
      step[i] = E / (f[i].abs + E / tau_max)
      # Расчет значений шага интегрирования по формуле для данных функций
    end
    tau_min = step.min # Рассчет локальной погрешности
    dots << {t: t.round(3), u: u[0], m: 'Явный'}
    for i in 0..(u.size - 1) do
      u[i] += tau_min * f[i] # Пересчет значений с учетом локальной погрешности
    end
    t += tau_min # Корректировка параметра
    iter += 1
  end
  puts "\tКоличество итераций: #{iter}, Значения u: #{round ? u.map {|x| x.round(3)} : u}" if out == true
  return u, dots
end
#
def FN(x, yk, tau, a, k)
  fn = []
  for i in 0..(yk.size - 1) do
    fn[i] = x[i] - yk[i] - tau * self.send("func#{i.to_s}", x, a, k)
  end
  i = 0
  # puts "#{x[i]} - #{yk[i]} - #{tau} * #{self.send("func#{i.to_s}", x, a, k)} = #{fn[i]}"
  return fn
end

def NewtonMethod(x, yk, tau, a, k)
  iter, size, eps = 1, x.size - 1, 1e-6
  fn = FN(x, yk, tau, a, k)
  for z in 0..50 do
    b = fn.map { |e|  -e}
    for i in 0..size do
      for j in 0..size do
        x[j] += eps;
        FN(x, yk, Tau, a, k, Fn);
        f1 = Fn[i]

        x[j] -= eps + 1e-16;
        FN(x, yk, Tau, a, k, Fn);
        f2 = Fn[i];

        Jf[i][j] = (f1 - f2) / eps;
      }
    }
    Gauss(Jf, b, dx);
    for (int i = 0; i < n; i++)
      x[i] += dx[i];

    d1 = fabs(b[0]);
    for (int i = 1; i < n; i++)
      if (fabs(b[i]) > d1)
        d1 = fabs(b[i]);

    if (fabs(x[0]) < 1)
      d2 = fabs(dx[0]);
    else
      d2 = fabs(dx[0] / x[0]);

    for (int i = 1; i < n; i++)
    {
      if (fabs(x[i]) < 1)
        if (d2 < fabs(dx[i]))
          d2 = fabs(dx[i]);
        else
          if (d2 < fabs(dx[i] / x[i]))
            d2 = fabs(dx[i] / x[i]);
    }
    iter++;

    if (d1 > e1 || d2 > e2) break;
  }
end

def EulerImplicit(u, a, k, out = false, round = false)
  tau, t, y, e, n, iter = {}, {'k' => 0}, {}, [], u.size - 1, 0
  y['k'] = y['k + 1'] = y['k - 1'] = u
  tau['min'], tau['max'], tau['arr'] = 0.01, 1, []
  tau['k - 1'] = tau['k'] = tau['min']
  while t['k'] < T do
    t['k + 1'] = t['k'] + tau['k']
    NewtonMethod(y['k + 1'], y['k'], tau['k'], a, k)
    r = true
    for i in 0..n do
      e[i] = -((tau['k'] / (tau['k'] + tau['k - 1']))*(y['k + 1'][i] - y['k'][i] - tau['k'] / tau['k - 1']*(y['k'][i] - y['k - 1'][i])))
      if e[i].abs > E && !r then
        tau['k'] /= 2.0
        tau['k + 1'] = tau['k']
        for j in 0..n do
          y['k + 1'][j] = y['k'][j]
        end
        r = false
      end
    end

    next if r

    for i in 0..n do
      tau['arr'][i] = tau['k'] / 2.0 if e[i].abs > E
      tau['arr'][i] = tau['k'] if e[i].abs > (E / 4.0) && e[i].abs <= E
      tau['arr'][i] = tau['k'] * 2 if e[i].abs <= E / 4.0
    end

    tau['k + 1'] = tau['arr'].min
    for i in 0..n do
      y['k - 1'][i] = y['k'][i]
      y['k'][i] = y['k + 1'][i]
    end

    tau['k - 1'] = tau['k']
    tau['k'] = tau['k + 1']
    t['k'] = t['k + 1']
     iter += 1
  end
  return y['k']
end
