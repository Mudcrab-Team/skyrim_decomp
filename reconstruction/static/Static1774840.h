// Source exposure: binary-analysis; no external implementation source reused.
// Static1774840, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1774840;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1774840*);
    virtual void release(Static1774840*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1774840*);
struct Static1774840 {
    void* value;
    Static1774840();
    ~Static1774840() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
