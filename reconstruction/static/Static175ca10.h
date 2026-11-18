// Source exposure: binary-analysis; no external implementation source reused.
// Static175ca10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175ca10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175ca10*);
    virtual void release(Static175ca10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175ca10*);
struct Static175ca10 {
    void* value;
    Static175ca10();
    ~Static175ca10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
