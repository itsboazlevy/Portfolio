template <class S, class B>							
class street_t
{
	public:
		street_t() 											{}
		street_t(const street_t& _str);						{id = _str.getId();}
		street_t& operator = (const street_t& _str)			{id = _str.getId(); return this;}
		street_t& operator = (street_t& _str) const			{_str.setId(id); return this;}
		~street_t()  										{size_t i; for(i=0; i< bv.size(); i++)
															delete[] bv[i];}
		void setId(const S& _id)							{id = _id;}
		const S& getId() const 								{return id;}
		void addBuilding(const building_t<B>* _buiPtr)		{data.insert(bv.end(), _buiPtr);}
		const building_t<B>* getBuilding (size_t _i) const	{return bv[_i];}
	private:
		S id;
		vector<building_t<B>*> bv; 		

};

