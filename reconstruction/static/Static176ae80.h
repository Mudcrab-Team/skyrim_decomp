// Source exposure: binary-analysis; no external implementation source reused.
// Static176ae80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176ae80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176ae80*);
    virtual void release(Static176ae80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176ae80*);
struct Static176ae80 {
    void* value;
    Static176ae80();
    ~Static176ae80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
