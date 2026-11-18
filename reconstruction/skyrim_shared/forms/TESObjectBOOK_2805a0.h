// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// TESObjectBOOK: STANDIN EXE_RTTI
// BookRequest, BookManager, GetManager, HandleRequest, Function2805a0: GUESS(low)
#pragma once
class TESObjectBOOK;
struct BookRequest { TESObjectBOOK* book; bool flag; };
class BookManager { public: void HandleRequest(BookRequest&); };
class TESObjectBOOK { public: BookManager* GetManager(); void Function2805a0(bool); };
