// Source exposure: binary-analysis; no external implementation source reused.
// Static1775510, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1775510;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1775510*);
    virtual void release(Static1775510*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1775510*);
struct Static1775510 {
    void* value;
    Static1775510();
    ~Static1775510() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
