#include "FileOpener.hpp"

FileOpener::FileOpener(std::ifstream &file, const char *fileName) : fileToRead(&file)
{
	fileToRead->open(fileName);
	setContent();
}

FileOpener::~FileOpener()
{
	if (fileToRead && fileToRead->is_open())
		fileToRead->close();
}

std::string	FileOpener::getContent()
{
	return (content);
}

void		FileOpener::setContent()
{
	if (fileToRead->is_open())
	{
		stream_catch << fileToRead->rdbuf();
		content = stream_catch.str();
	}
	else
		content = "No content in file";
}

