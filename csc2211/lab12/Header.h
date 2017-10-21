class figure{		//declaration of class figure with virtual functions
public:
	virtual void erase();
	virtual void draw();
    virtual	void center();
};

//class figure{		//declaraction of class figure (included for part 1 but commmented out for part 2)
//public:
//	void erase();
//	void draw();
//	void center();
//};

class Rectangle : public figure{	//declaration of class rectangle
public:
	void erase();
	void draw();
};

class Triangle : public figure{		//declaration of class triangle
public:
	void erase();
	void draw();
};