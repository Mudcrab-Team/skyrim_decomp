// Source exposure: binary-analysis; no external implementation source reused.
// Static177eb10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177eb10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177eb10*);
    virtual void release(Static177eb10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177eb10*);
struct Static177eb10 {
    void* value;
    Static177eb10();
    ~Static177eb10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
