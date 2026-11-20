// Source exposure: binary-analysis; no external implementation source reused.
// Static1785460, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1785460;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1785460*);
    virtual void release(Static1785460*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1785460*);
struct Static1785460 {
    void* value;
    Static1785460();
    ~Static1785460() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
