#ifndef BOOKVISITOR_H
#define BOOKVISITOR_H

class Comic;
class CSBook; // look, both these classes exist!

class BookVisitor{
	public:
		virtual void visit (Comic &) = 0;
		virtual void visit (CSBook &) = 0;
};

#endif
