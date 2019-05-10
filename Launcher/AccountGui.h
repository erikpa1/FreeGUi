#pragma once
#include "GuiItem.h"
#include "Layout.h"
#include "Buton.h"
#include "../FreeGui/TextField.h"

class AccountGui : public GuiItem
{
public:

	AccountGui();
	~AccountGui();

	void BuildYourSelf(Layout& layout) override;

private:

	bool _someoneLogged = false;

	Buton * _username;	
	Buton * _userPassword;
	TextField * _usernameText;
	TextField * _passwordText;
	Buton * _login;
	
		
};


