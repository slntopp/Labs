template<typename IntT>
class Iterator {
	static const size_t MAX_WIDTH = sizeof(IntT) * CHAR_BIT;
    private:
        struct IncrementData
        {
            size_t  m_counter;         //	current counter value
            size_t  m_counterLimit;    //	number of iterations, usually B, but B - 1 for last increment
            IntT    m_increment;       //	increment value
        };

    public:
        inline Iterator(const size_t base,const IntT * powers): m_base(base), m_powers(powers){
            m_value = POWER(0);
            SetWidth(1);
        }

        inline void operator ++(){
            //	always increment by basic
            m_value += m_basicIncrement;

            size_t i = 0;
            do {
                if (--m_counters[i].m_counter)
                    return;

                //	reset counter
                m_counters[i].m_counter = m_counters[i].m_counterLimit;
                //	correct value on digit overflow
                m_value += m_counters[i].m_increment;
            } while (++i < m_countersSize);

            //	prepare to next width
            SetWidth(m_width + 1);
        }

        inline const IntT & operator *() const
        {
            return m_value;
        }

    private:
        void SetWidth(size_t width){
            m_width = width;
            m_countersSize = (m_width + 1) / 2;

            m_basicIncrement = POWER(m_countersSize - 1);

            size_t i;
            for (i = 0; i < m_countersSize - 1; ++i) {
                m_counters[i].m_counter = m_counters[i].m_counterLimit = m_base;
                m_counters[i].m_increment = POWER(m_countersSize - i - 2) - POWER(m_countersSize - i - 2) * m_base * m_base;
            }
            m_counters[i].m_counter = m_counters[i].m_counterLimit = m_base - 1;
            m_counters[i].m_increment = POWER(0) - POWER(1);

            if (m_width & 1)
                m_counters[0].m_increment += POWER(m_countersSize);
            else
                m_basicIncrement += POWER(m_countersSize);
        }

        IntT           m_value;                 //	current value
        IntT           m_basicIncrement;        //	basic increment (100... for odd width, 1100... for even width
        size_t         m_countersSize;          //	just greater half of width: (width + 1) / 2
        IncrementData  m_counters[MAX_WIDTH];
        size_t         m_width;                 //	current width = number of digits
        size_t         m_base;
    	const IntT   * m_powers;
};
