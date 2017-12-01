require 'pry'
require 'json'
require './art.rb'
require './gauss.rb'
#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#

data, ex = JSON.parse(File.read('in.json')), ARGV[0] # Получение данных о матрицах А и b из JSON файла in.json и номера набора входных данных из консоли
a, b, x, n = data[ex]['A'], data[ex]['b'], data[ex]['b'].class.new(data[ex]['A'].size), data[ex]['A'].size
b_copy = b
# Инициализация двумерного массива матрицы А, одномерного b, массива ответов x и переменной размера матрицы n

x = GetXbyGaussMethod(a, b, n) # Функция из /include/gauss.rb для нахождения решения системы уравнения методом Гаусса.
# Код с комментами там же

puts "Полученные значения: #{x.out}"

# Подсчет вектора невязки и его нормы. Кратко, вектор невязки это F = A x X - b
# Норма вектора невзки это самое большое по модулю значение внутри вектора невязки
data, ex = JSON.parse(File.read('in.json')), ARGV[0] # Получение данных о матрицах А и b из JSON файла in.json и номера набора входных данных из консоли

a_copy = data[ex]['A']
F = GetDiscVector(a_copy, b_copy, x)

puts "Вектор невязки: #{F.to_a.out}, Норма вектора невязки: #{N = F.max_by {|item| item.abs} }"