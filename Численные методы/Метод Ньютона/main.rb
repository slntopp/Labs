require 'pry'
require 'json'
require '../../include/gauss.rb'
require './funcs.rb'
require '../FirstLab/art.rb'

LIMIT = 100

if ARGV[0].nil?
    puts "No data was entered"
    Kernel.exit
end

eq, x, iter, delta = JSON.parse(File.read('./eq.json'))[ARGV[0]], [], 0, true
b = Array.new(eq.size)
for i in 1..(eq.size) do x << ARGV[i].to_f end
puts "Система уравнений:"
eq.each do | item |
    puts "> " + item
end

while delta do
    break if iter == LIMIT
    for i in 0..(b.size - 1) do
        b[i] = func_compute(eq[i], x) * (-1)
    end
    dx = GetXbyGaussMethod(ComputeJakobiMatrix(eq, x), b, eq.size)
    for i in 0..(dx.size - 1) do
        delta = dx[i].to_f.abs >= E
        x[i] += dx[i].to_f
    end
    for i in 0..(eq.size - 1) do
        b[i] = func_compute(eq[i], x) * (-1)
    end
    iter += 1
end
puts "Корни:"
for i in 0..(x.size - 1) do
    puts "#{VARS[i]} = #{x[i]}"
end
puts "Количество итераций: #{iter}"