#include "FerropfApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
FerropfApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

FerropfApp::FerropfApp(InputParameters parameters) : MooseApp(parameters)
{
  FerropfApp::registerAll(_factory, _action_factory, _syntax);
}

FerropfApp::~FerropfApp() {}

void 
FerropfApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<FerropfApp>(f, af, s);
  Registry::registerObjectsTo(f, {"FerropfApp"});
  Registry::registerActionsTo(af, {"FerropfApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
FerropfApp::registerApps()
{
  registerApp(FerropfApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
FerropfApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  FerropfApp::registerAll(f, af, s);
}
extern "C" void
FerropfApp__registerApps()
{
  FerropfApp::registerApps();
}
