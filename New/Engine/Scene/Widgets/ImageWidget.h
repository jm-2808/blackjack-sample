//=============================================================================================

#ifndef ENGINE_WIDGET_IMAGE_H
#define ENGINE_WIDGET_IMAGE_H

//=============================================================================================

#include "../Widget.h"

//=============================================================================================

#include "../../Types/ASCIIImage.h"

//=============================================================================================

class ImageWidget : public Widget
{
public:
	ImageWidget();
	ImageWidget(ASCIIImage image);
	~ImageWidget();

	//=== General ===========================================================
public:
	virtual const std::string Render() override;

	//=== Image =============================================================
public:
	const ASCIIImage GetImage() const { return Image; }
	void SetImage(ASCIIImage image) { Image = image; }

private:
	ASCIIImage Image;

};

//=============================================================================================

#endif

//=============================================================================================