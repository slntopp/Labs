#undef POWER
#define POWER(exp)  m_powers[exp]

template<typename IntT>
struct BaseData
{
	static const size_t MAX_WIDTH = sizeof(IntT) * CHAR_BIT;

	BaseData(
		size_t base,
		IntT maxValue)
		: m_base(base)
	{
		POWER(0) = IntT(1);
		for (size_t i = 1; i < MAX_WIDTH; ++i) {
			POWER(i) = POWER(i - 1) * IntT(base);
			if (POWER(i) >= maxValue) {
				m_maxWidth = i - 1;
				break;
			}
		}
	}

	size_t  m_base;
	size_t  m_maxWidth;
	IntT    m_powers[MAX_WIDTH];
};