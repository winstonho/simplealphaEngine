#include "FontUtil.h"
#include <AEEngine.h>

namespace FontUtil
{
	void PrintText(int FontID, float x, float y, float scale, float r, float g, float b, const char* format, ...)
	{
		va_list args;	//  Variable argument list
		int len;		//	String length

		char* text;	//	Text
		va_start(args, format);

		//  Return the number of characters in the string referenced the list of arguments.
		//  _vscprintf doesn't count terminating '\0' (that's why +1)
		len = _vscprintf(format, args) + 1;

		//  Allocate memory for a string of the specified size
		text = (char*)malloc(len * sizeof(char));

		//  Write formatted output using a pointer to the list of arguments
		vsprintf_s(text, len, format, args);

		//  End using variable argument list 
		va_end(args);

		AEGfxSetBlendMode(AE_GFX_BM_BLEND);
		AEGfxSetRenderMode(AE_GFX_RM_COLOR);
		AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
		AEGfxPrint(FontID, text, x, y, 1.0, r, g, b);

		//free the text after use.
		free(text);

	}
}