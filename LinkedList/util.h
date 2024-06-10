#pragma once

//Helper function we'll likely need throughout the entire program.
#define SAFE_DELETE(p) if(p) delete p; p = nullptr; 