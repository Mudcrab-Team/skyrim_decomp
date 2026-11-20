// Source exposure: binary-analysis; no external implementation source reused.
// Static175c060, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175c060;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175c060*);
    virtual void release(Static175c060*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175c060*);
struct Static175c060 {
    void* value;
    Static175c060();
    ~Static175c060() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
