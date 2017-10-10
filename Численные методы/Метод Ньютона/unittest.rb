require './funcs.rb'
require 'json'

eq, x = JSON.parse(File.read('./eq.json'))[ARGV[0]], []
for i in 1..(eq.size) do x << ARGV[i].to_f end

eq.each do | item |
    puts func_compute(item, x).to_f.round(9)
end

# ln(1 + (x + y) / 5) - sin(y / 3) - x + 1.1
# cos(x * y / 6) - y + 0.5