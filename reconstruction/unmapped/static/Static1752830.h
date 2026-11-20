// Source exposure: binary-analysis; no external implementation source reused.
// Static1752830, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1752830;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1752830*);
    virtual void release(Static1752830*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1752830*);
struct Static1752830 {
    void* value;
    Static1752830();
    ~Static1752830() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
