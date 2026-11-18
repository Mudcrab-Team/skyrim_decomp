// Source exposure: binary-analysis; no external implementation source reused.
// Static1752f10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1752f10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1752f10*);
    virtual void release(Static1752f10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1752f10*);
struct Static1752f10 {
    void* value;
    Static1752f10();
    ~Static1752f10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
