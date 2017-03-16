#pragma once

struct IPainter;
struct IDesigner;
struct ICanvas;

class CClient
{
public:
	CClient(std::unique_ptr<IPainter> && painter, std::unique_ptr<IDesigner> && designer);
	~CClient();

	void MakePictureOrder();
private:
	std::unique_ptr<IPainter> m_pPainter;
	std::unique_ptr<IDesigner> m_pDesigner;
	std::unique_ptr<ICanvas> m_pCanvas;
};

