#pragma once
#include "PopupCollection.h"
#include "Label.h"
#include "../FreeGui/TextField.h"
#include "../FreeGui/GuiPair.h"

class AppWindow;

class LoginGui : public PopupCollection
{

public:

	LoginGui();
	~LoginGui();

	void ShowBlocking() override;


private:

	Sp<AppWindow> _window;

	Sp<Label> _nameDescriptor;
	Sp<TextField> _nameField;

	Sp<Label> _passwordDescritor;
	Sp<TextField> _passwordField;

	Sp<GuiPair> _namePair;
	Sp<GuiPair> _passwordPair;
	
	
};
