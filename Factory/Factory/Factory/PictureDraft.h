#pragma once
#include <istream>
#include <boost/iterator/indirect_iterator.hpp>
#include <vector>
#include "Shape.h"

class CPictureDraft
{
public:
	typedef std::vector<std::unique_ptr<CShape>> Storage;

	CPictureDraft();
	~CPictureDraft();

	bool IsEmpty()const;

	typedef boost::indirect_iterator<Storage::const_iterator, const CShape&> ConstIterator;

	ConstIterator begin()const;

	ConstIterator end()const;


	void AddShape(std::unique_ptr<CShape> && shape);

	CPictureDraft(CPictureDraft &&) = default;
	CPictureDraft& operator=(CPictureDraft &&) = default;

	CPictureDraft(const CPictureDraft &) = delete;
	CPictureDraft& operator=(const CPictureDraft &) = delete;
private:
	std::vector<std::unique_ptr<CShape>> m_shapes;
};