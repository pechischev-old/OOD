#include "stdafx.h"
#include "Client.h"
#include "Designer.h"
#include "PictureDraft.h"
#include "Painter.h"

#include "Canvas.h"


CClient::CClient(IPainter & painter, IDesigner & designer)
	: m_painter(painter)
	, m_designer(designer)
	, m_pCanvas(std::make_unique<CCanvas>(std::cout))
{
}

CClient::~CClient()
{
}

void CClient::DrawPicture(std::istream & cin)
{
	auto draft = m_designer.CreateDraft(cin);
	m_painter.DrawPicture(draft, *m_pCanvas);
}
