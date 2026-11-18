// Source exposure: binary-analysis; no external implementation source reused.
// Static1779840, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1779840;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1779840*);
    virtual void release(Static1779840*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1779840*);
struct Static1779840 {
    void* value;
    Static1779840();
    ~Static1779840() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
