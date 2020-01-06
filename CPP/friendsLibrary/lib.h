class borrower_t
{
	friend class borrowerAdmin_t;
	public:
		borrower_t(const char* _name, size_t _phoneNum, size_t _id, const char* address);
		virtual ~borrower_t();
		void addBook (const book_t& book); 
		book_t& removeBook (size_t _ISBN) throw(size_t);
		size_t getBooksNum () const;
		const char* getName() const;
		size_t getPhoneNum() const;
		size_t getId() const;
		const char* getAddress() const;
protected:
		void setPhoneNum(size_t _phoneNum) throw(size_t);
		int setAddress(const char* _address);

	private:
		borrower_t(const borrower_t& _borrower);
		borrower_t& operator = (const borrower_t& _borrower);
		const char* name;
		size_t phoneNum;
		const size_t id;
		char* address;
		List* <book_t*>;//ISBN into ptr 
}

class book_t
{
	public:
		book_t(const char* _title,const char* _author, size_t _ISBN);
		virtualborrowerAdmin_t ~book_t(); 
		const char* GetTitle() const;
		size_t GetISBN() const;
		const char* GetAuthor() const;
	private:
		book_t& operator = (const book_t& _book);
		book_t(const book_t& _book);
		const char* title;
		const char* author;		
		const size_t ISBN;	
}

class bookCard_t
{
	public:
		size_t getCopies() const;
		size_t getBorCopies() const;
		size_t numAvailableCopies() const;
		void setCopies(size_t _newCopies);
		bool increaseBorCopies(); 
		bool decreaseBorCopies(); 
		int& GetBookPlace()const; 
		int SetBookPlace(const int& bookPlace);
	private:
		book_t* bookPlace;
		size_t copies;
		size_t borCopies;		
} 

class bookCardAdmin_t
{
	public:
		AddBook
		RemoveBook
		FindBook
		GiveBook
		GetBook
	private:
		NumBooks
}

class borrowerAdmin_t
{
	public:
		AddBorrower
		RemoveBorrower
		FindBorrower
	private:
		NumBorrowers
}

class library
{
	public:
		size_t GetBookAmount()const;
		size_t GetBorrowersNum()const; {borrowerAdmin.get()}
		void AddBook (const book_t& book, size_t copies);
		int BorrowBook (size_t _ISBN, size_t borrowerId);
		// go ask book admin		
		// is there ISBN
        // copies borrowed - update by ID
	private:
		Hash* <> books;
		bookCardAdmin_t bookAdmin;
		borrowerAdmin_t borrowerAdmin;
		size_t bookAmount;
		size_t borrowersNum;		
}

