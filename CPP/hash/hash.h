// general design no implementation.
typedef 300 CAP;

template <typename T, typename Tfunc>
class hash
{
	public:
		hash(const Tfunc& _tfunc, ): data(CAP), n(0), hashFunc(_tfunc%) {}
		virtual ~hash() {}
		int find(const T& _t) const;
		int insert(const T& _t);
		int erase(const T& _t);
		bool empty() const { return (n == 0); }
		size_t size() const { return n; }
		
	private:
		size_t n;
		Tfunc hashFunc;
		const hash& hash(const hash& _hash);
		const hash& operator = (const hash& _hash);
		vector<forward_list<T>> data;
	
}

