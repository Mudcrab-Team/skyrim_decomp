// Source exposure: binary-analysis; no external implementation source reused.
// Static175b430, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175b430;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175b430*);
    virtual void release(Static175b430*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175b430*);
struct Static175b430 {
    void* value;
    Static175b430();
    ~Static175b430() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
