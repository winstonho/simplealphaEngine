// ---------------------------------------------------------------------------
// includes

#include "AEEngine.h"
#include "Engine.h"


void PrintText(int FontID, f32 x, f32 y,f32 scale, float r, float g, float b, char* format, ...)
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
	AEGfxPrint(FontID, text, x, y,1.0, r, g, b);

	//free the text after use.
	free(text);

}

// ---------------------------------------------------------------------------
// main

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	///////////////////////
	// Variable declaration

	
	
	
	// Variable declaration end
	///////////////////////////


	/////////////////
	// Initialization

	Engine::GetInstance().InitScene(hInstance, nCmdShow, 800, 600, 1, "Demo");
	Engine::GetInstance().Load();

	// Initialization end
	/////////////////////
	Engine::GetInstance().Update();


		

		// Drawing object 2 - (first) - No tint
		//AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
		// Set position for object 2
		//AEGfxSetTransform(trans.m);
		//AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
		//AEGfxSetTransparency(1.0f);
		// Set texture
		//AEGfxTextureSet(pTex1, 0.0f, 0.0f);
		// Drawing the mesh (list of triangles)
		//AEGfxMeshDraw(pMesh2, AE_GFX_MDM_TRIANGLES);

		//PrintText(fontId, 0.5, 0.5, 1.f, 1.f, 1.f, strBuffer);
		
		// Game loop draw end
		/////////////////////


	



	Engine::GetInstance().Destory();

	
}