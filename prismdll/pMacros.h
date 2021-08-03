#pragma once

#define PDLL __declspec(dllexport)
#define PDLL_THIS_P __thiscall*
#define PDLL_FAST_P __fastcall*
#define PDLL_THIS __thiscall
#define PDLL_FAST __fastcall
#define PDLL_CLASS(__CLASS_NAME__) class __CLASS_NAME__
