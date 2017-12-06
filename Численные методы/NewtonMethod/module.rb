require '../../include/gauss.rb'
require './funcs.rb'
require '../Метод Гаусса/art.rb'

LIMIT = 50 # Ограничение количества итераций в основном цикле

def NewtonMethod(eq, x)
  b, old_x, iter, delta =  Array.new(eq.size), x.max_by {|i| i.abs}, 0, true
  while delta do
      break if iter == LIMIT # Выход из цикла в случае достижения ограничения итераций
      for i in 0..(b.size - 1) do # Заполнение вектора результатами подстановки начальных приближений в уравнения с обратным знаком
          b[i] = func_compute(eq[i], x) * (-1) # func_compute вычисляет уравнение данное первым параметром, с переменными данными во втором
      end
      dx = GetXbyGaussMethod(ComputeJakobiMatrix(eq, x), b, eq.size) # Вычисление dX путем вычисления методом Гаусса системы уравнений из Якобиана
      for i in 0..(dx.size - 1) do # Изменение приближения на dX
          x[i] += dx[i].to_f
      end
      delta = (
          (b.max_by { |item| item.abs} > E) &&
          ((x.max_by { |item| item.abs} - old_x).abs / (x.max_by { |item| item.abs} >= 1 ? x.max_by { |item| item.abs} : 1).abs > E)
      )
      iter += 1 # Изменение счетчика
      old_x = x.max_by { |item| item.abs}
  end
  return x, iter
end
