template <class B>							
class building_t
{
	public:
		building_t() 											{}
		building_t(const building_t& _bui);						{id = _bui.getId();}
		building_t& operator = (const building_t& _bui)			{id = _bui.getId(); return this;}
		building_t& operator = (building_t& _bui) const			{_bui.setId(id); return this;}
		~building_t()  											{}
		void setId(const B& _id)								{id = _id;}
		const B& getId() const 									{return id;}
	private:
		B id;
};

