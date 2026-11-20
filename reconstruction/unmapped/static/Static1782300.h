// Source exposure: binary-analysis; no external implementation source reused.
// Static1782300, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1782300;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1782300*);
    virtual void release(Static1782300*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1782300*);
struct Static1782300 {
    void* value;
    Static1782300();
    ~Static1782300() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
