// Source exposure: binary-analysis; no external implementation source reused.
// Static1748460, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1748460;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1748460*);
    virtual void release(Static1748460*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1748460*);
struct Static1748460 {
    void* value;
    Static1748460();
    ~Static1748460() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
