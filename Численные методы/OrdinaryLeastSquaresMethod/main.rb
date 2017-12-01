require './art.rb'
require '../../include/gauss.rb'
require 'pry'

pow = ARGV[0].to_i
if pow == 0 then
  puts 'Требуется задать степень полинома первым аргументом!'
  Kernel.exit(1)
end

X, Y = [0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100], [1.00762, 1.00392, 1.00153, 1, 0.99907, 0.99852, 0.99826, 0.99818, 0.99828, 0.99849, 0.99878, 0.99919, 0.99967, 1.00024, 1.00091, 1.00167, 1.00253, 1.00351, 1.00461, 1.00586, 1.00721]

N, powered_x, multiplied_yx, sumx = X.size - 1, Array.new(2 * pow + 1), [], []
#
# for k in 0..(2 * pow + 1) do
#   for i in 0..(X.size - 1) do
#     powered_x[k] += X[i]**k
#   end
# end

for k in 0..(2 * pow + 1) do
  powered_x[k] = 0
  for i in 0..(X.size - 1) do
    powered_x[k] += (X[i] ** k)
  end
end

for l in 0..(pow) do
  multiplied_yx[l] = 0
  for i in 0..N do
    multiplied_yx[l] += Y[i] * (X[i] ** l)
  end
end

for l in 0..(pow) do
  sumx[l] = []
  for j in 0..(pow) do
    sumx[l][j] = powered_x[l + j]
  end
end

sumx[0][0] = N + 1

a = GetXbyGaussMethod(sumx.clone, multiplied_yx.clone, pow + 1)

puts "| ----- Y ----- | ----- X ----- |  Значение после апроксимации  |"
out = ""
for i in 0..N do
  y = 0
  for j in 0..pow do
    y += a[j] * (X[i] ** j)
  end
  puts "|\t#{Y[i]}\t|\t#{X[i]}\t|\t#{y}\t|"
  out += "          [#{X[i].to_s}, #{Y[i].to_s}, #{y.to_s}],\n"
end
puts "\t\t\t Соответствующие графики в файле graphs.html"

residual_dispersion = 0
mult = 1.0 / (N - pow)
for i in 0..(N - 1) do
  for k in 0..(pow - 1) do
    d = a[k] * ( X[i] ** k)
    diff = mult * ( ( Y[i] - d ) ** 2)
    residual_dispersion += diff
  end
end

puts "Остаточная дисперсия: #{residual_dispersion}"
puts "Ср. квад. отклонение: #{residual_dispersion ** 0.5}"

template = File.read('template.html').split(/\n/)
template[template.index('###')] = out
File.open('graphs.html', 'w') { |file| file.write(template.join("\n")) }
