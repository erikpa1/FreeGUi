#include "LoginGui.h"

LoginGui::LoginGui()
{
	_window = new AppWindow(300, 300, 500, 500, "Crios");

	_nameDescriptor = new Label();
	_nameDescriptor->SetText("Name");
	_nameDescriptor->SetButtonColor(0.5, 0.5, 0.5, 0);
	_nameField = new TextField();
	//_nameField->SetColor(0.5, 0.5, 0.5, 1);
	
	_passwordDescritor = new Label();
	_passwordDescritor->SetText("Password");
	_passwordField = new TextField();
	   
	_namePair = new GuiPair(0, 0, 300, 50);
	_namePair->SetRelative();
	_passwordPair = new GuiPair(0, 200, 300, 50);

	_namePair->SetElements(_nameDescriptor.Get(), _nameField.Get(), 0.5);
	_passwordPair->SetElements(_passwordDescritor.Get(), _passwordField.Get(), 0.3);
	
	_window->AddElement(_namePair.Get());
	//_window->AddElement(_passwordPair.Get());

}

LoginGui::~LoginGui()
{

}

void LoginGui::ShowBlocking()
{
	_window->IndependentStart();
}
