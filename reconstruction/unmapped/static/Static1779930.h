// Source exposure: binary-analysis; no external implementation source reused.
// Static1779930, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1779930;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1779930*);
    virtual void release(Static1779930*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1779930*);
struct Static1779930 {
    void* value;
    Static1779930();
    ~Static1779930() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
