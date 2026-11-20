// Source exposure: binary-analysis; no external implementation source reused.
// Static1743620, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1743620;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1743620*);
    virtual void release(Static1743620*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1743620*);
struct Static1743620 {
    void* value;
    Static1743620();
    ~Static1743620() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
