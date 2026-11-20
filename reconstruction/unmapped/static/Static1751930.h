// Source exposure: binary-analysis; no external implementation source reused.
// Static1751930, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1751930;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1751930*);
    virtual void release(Static1751930*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1751930*);
struct Static1751930 {
    void* value;
    Static1751930();
    ~Static1751930() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
