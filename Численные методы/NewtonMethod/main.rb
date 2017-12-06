require 'json'
require '../../include/gauss.rb'
require './funcs.rb'
require '../Метод Гаусса/art.rb'

LIMIT = 50 # Ограничение количества итераций в основном цикле

if ARGV[0].nil? # Проверка на отсутствие входных данных
    puts "No data was entered"
    Kernel.exit
end

eq, x, iter, delta = JSON.parse(File.read('./eq.json'))[ARGV[0]], [], 0, true
if eq.nil? then
    puts "Записи #{ARGV[0]} в базе уравнений нет"
    Kernel.exit
end
# Массив уравнений(текстовых записей), массив переменных, счетчик итераций, условие выполнения(|dX| >= E)
b = Array.new(eq.size) # Вектор с результатами подстановки текущих приближений в уравнение
for i in 1..(eq.size) do
    if ARGV[i].nil? then
        puts "WARNING!: Начальные приближения введены не для всех переменных!"
        break
    end
end
for i in 1..(eq.size) do x << ARGV[i].to_f end # Заполнение массива переменных начальными приближениями
old_x = x.max_by {|i| i.abs}
puts "Система уравнений:" # Очевидно, вывод системы уравнений
eq.each do | item |
    puts "> " + item
end

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
puts "Корни:" # Вывод корней
for i in 0..(x.size - 1) do
    puts "#{VARS[i]} = #{x[i]}"
end
puts "Количество итераций: #{iter}"
