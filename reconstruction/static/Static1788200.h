// Source exposure: binary-analysis; no external implementation source reused.
// Static1788200, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1788200;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1788200*);
    virtual void release(Static1788200*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1788200*);
struct Static1788200 {
    void* value;
    Static1788200();
    ~Static1788200() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
