require 'math_engine'
require './defines.rb'

$engine = MathEngine.new
$engine.context.include_library MathDefines.new

def func_compute(equation, vars)
    for i in 0..vars.length - 1 do
        $engine.evaluate("#{VARS[i]} = #{vars[i]}")
    end
    return $engine.evaluate(equation)
end

def func_deriv(equation, vars, index)
    nvars = []
    vars.each do | item | nvars << item end
    nvars[index] += E
    return (func_compute(equation, nvars) - func_compute(equation, vars)) / E
end

def ComputeJakobiMatrix(equations, vars)
    res = Array.new(equations.length, 0)
    for i in 0..equations.length - 1 do
        res[i] = Array.new(vars.length, 0)
        for j in 0..vars.length - 1 do
            res[i][j] = func_deriv(equations[i], vars, j)
        end
    end
    return res
end