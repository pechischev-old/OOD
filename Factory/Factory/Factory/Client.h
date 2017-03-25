#pragma once

struct IPainter;
struct IDesigner;
struct ICanvas;

class CClient
{
public:
	CClient(IPainter & painter, IDesigner & designer);
	~CClient();

	void DrawPicture(std::istream & cin);
private:
	IPainter & m_painter;
	IDesigner & m_designer;
	std::unique_ptr<ICanvas> m_pCanvas;
};

