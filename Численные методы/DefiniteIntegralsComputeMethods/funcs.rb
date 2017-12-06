def Trapese(a, b, e)
    h, res = (b - a) * e, 0
    bar = ProgressBar.new(1 / e - 1, :elapsed, :bar, :percentage)
    for i in 1..(e**(- 1)) do
        res += f(a + i * h)
        bar.increment!
    end
    puts
    return (f(a) + 2 * res + f(b)) * h / 2.0
end

def SimpsonsF(a, b, e)
    h, m, mt4, mt2 = (b - a) * e, (1 / e) / 2, 0, 0
    bar = ProgressBar.new(m, :elapsed, :bar, :percentage)
    for i in 1..m do
        mt4, mt2 = mt4 + f(a + (2 * i - 1) * h), mt2 + f(2 * i * h)
        bar.increment!
    end
    mt4 += f(a + (2 * m) * h)
    bar.increment!
    puts
    return (h / 3.0) * (f(a) + 4 * mt4 + 2 * mt2 + f(a + 2 * m * h))
end

def TrapeseRight(a, b, e)
    result, n = 0.0, 1 / e
    bar = ProgressBar.new(2, :elapsed, :bar, :percentage)
    bar.increment!    
	while true do
		tmp, ifunc = result, 0.0
        h = (b - a) / n
        
		for i in 1..(n) do ifunc += f(a + i * h) end

		result = (h / 2.0) * (f(a) + f(b) + ifunc * 2.0)
		n *= 2	
        break if (tmp - result).abs < 3 * e
    end
    bar.increment!
    puts
    return result
end

def SimpsonsFRight(a, b, e)
	result, tmp = 0.0, 0
    n = 2 / e
    bar = ProgressBar.new(2, :elapsed, :bar, :percentage)
    bar.increment!    
	while true do
		tmp = result
		h = (b - a) / n

		f2, f3 = 0.0, f(a + h)
		for i in 2..n do
            f2 += f(a + i * h)
            f3 += f(a + (i + 1) * h)
            i += 2
        end

		result = (f(a) + f(b) + 2.0 * f2 + 4.0 * f3) * (h / 3.0)
		n *= 2
		break if (result - tmp).abs < e * 15
    end
    bar.increment!
    puts
    return result / 2.0
end