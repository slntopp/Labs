class MathDefines
    def ln(x)
        return Math.log(x)
    end
end

class Array
    def eachp(num)
        for i in 0..self.length - 1 do
            self[i] += num
        end
        return self
    end
end
VARS = ['x', 'y', 'z', 'a', 'b', 'c']
E = 0.00000000001
