/* this module is incorrect */
template <class T>							
class city_t
{
	public:
		city_t() 										{}
		city_t(const street_t& _city)					{id = _city.getId();}
		city_t& operator = (const city_t& _city)		{id = _city.getId(); return this;}
		city_t& operator = (city_t& _city) const		{_city.setId(id); return this;}
		~city_t()  										{size_t i; for(i=0; i< sv.size(); i++) delete[] sv[i];}
		void setId(const T& _id)						{id = _id;}
		const T& getId() const 							{return id;}
		void addStreet(const street_t* _strPtr)			{data.insert(sv.end(), _strPtr);}
		const street_t* getStreet (size_t _i) const		{return bv[_i];}
	private:
		T id;
		vector<street_t*> sv; 		

};

