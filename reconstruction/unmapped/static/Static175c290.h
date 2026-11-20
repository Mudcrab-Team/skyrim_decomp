// Source exposure: binary-analysis; no external implementation source reused.
// Static175c290, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175c290;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175c290*);
    virtual void release(Static175c290*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175c290*);
struct Static175c290 {
    void* value;
    Static175c290();
    ~Static175c290() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
