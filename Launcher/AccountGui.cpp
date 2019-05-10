#include "AccountGui.h"

AccountGui::AccountGui()
{
	_username = new Buton(0, 0, 0, 0);
	_username->SetText("User name: ");
	_userPassword = new Buton(0, 0, 0, 0);
	_userPassword->SetText("Password");
	_login = new Buton(0, 0, 0, 0);
	_usernameText = new TextField(0, 0, 0 , 0);
	_passwordText = new TextField(0, 0, 0, 0);
}

AccountGui::~AccountGui()
{
	delete _usernameText;
	delete _userPassword;
	delete _login;
	delete _usernameText;

	_usernameText = nullptr;
	_userPassword = nullptr;
	_login = nullptr;
	_usernameText = nullptr;
}

void AccountGui::BuildYourSelf(Layout & layout)
{
	layout.AddElement(*_username);
	layout.AddElement(*_usernameText);
	layout.AddElement(*_userPassword);
	layout.AddElement(*_usernameText);
	layout.AddElement(*_login);	
	
	//_usernameText->SetPasswordField(true);
	_usernameText->SetNumericOnly(true);
	
}