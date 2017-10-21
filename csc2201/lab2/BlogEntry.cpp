
#include "BlogEntry.h"

BlogEntry::BlogEntry()
{
	Date now;
	created = now;
	modified = created;
}

BlogEntry::BlogEntry(const Text& initAuthor, const Text& initContents)
{
	author = initAuthor;
	contents = initContents;
}

Text BlogEntry::getAuthor() const
{
	//Text temp;
	return author;
}

Text BlogEntry::getContents() const
{
	//Text temp;
	return contents;
}

Date BlogEntry::getCreateDate() const
{
	//Date date;
	return created;
}

Date BlogEntry::getModifyDate() const
{
	//Date date;
	return modified;
}

void BlogEntry::setAuthor(const Text& newAuthor)
{
	author = newAuthor;
}

void BlogEntry::setContents(const Text& newContents)
{
	contents = newContents;
}

void BlogEntry::printHTML( ostream& out ) const
{
	out << "<html>" << endl;
	out << "<body>" << endl;
	out << "<h1>" <<  getAuthor() << "</h1>" << endl;
	out << "<p>" << endl;
	out << getContents() << endl;
	out << "</p>" << endl;
	out << "<p>" << endl;
	out << "Created: " << created << endl;
	out << "</p>" << endl;
	out << "<p>" << endl;
	out << "Last modified: " << modified << endl;
	out << "</p>" << endl;
	out << "</body>" << endl;
	out << "</html>" << endl;
}