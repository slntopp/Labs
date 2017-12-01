class Array
    def out(b = nil) # Метод для форматированного вывода матриц и расширенных матриц
        return self.one_out if self[0].class.to_s == "Float"
        self.each do | item |
            puts "| #{item.join("\t")} | " + (b.nil? ? "" : "#{b[self.index item]} |") # Между || записывается строка
            # из элементов строки разделенная табуляцией, а если в метод передана матрица свободных членов b, дописываются
            # соответсвующие значения и доставляется |
        end
    end
    def one_out
        out = ""
        for i in 0..(self.size - 1) do
            out += (self[i].round(3)).to_s
            out += " "
        end
        return "| #{out}|"
    end
    def make_full(b = Array.new(self.size, 0)) # Метод генерации расширенной матрицы из матриц Коэффициентов и Свободных Членов
        return self.each { |item| item << b[self.index item]} # В каждую строку матрицы коэффициентов добавляется элемент из массива b
    end
    def divide # Метод разделения расширенной матрицы на матрицу коэффициентов и матрицу свободных членов
        return self.collect { |item| item.pop }, self # Из расширенной матрицы удаляются последние элементы строк и записываются в массив
        # вторым параметром возвращается то, что остается от расширенной матрицы, т.е. матрица коэффициентов
    end
    def to_f
        for i in 0..(self.size - 1) do
            self[i] = self[i].to_f
        end
    end
end

class String
    def out
        return self
    end
end

class Matrix
    def []=(i, j, value)
        @rows[i][j] = value
    end
end

class Vector
    def []=(i, value)
        @elements[i] = value
    end
end