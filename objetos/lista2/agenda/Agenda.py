from Contact import Contact

class Agenda:
    def __init__(self) -> None: self.contacts: list[Contact] = []

    def retrieve_contacts(self) -> list[Contact]:
        return ', '.join([str(contact) for contact in self.contacts])

    def search_contact(self, name: str) -> Contact:
        for contact in self.contacts:
            if contact.name == name: return contact
        return None

    def sort_contacts(self) -> None:
        for n in range(len(self.contacts) - 1, 0, -1):
            for i in range(n):
                if self.contacts[i] > self.contacts[i + 1]:
                    self.contacts[i], self.contacts[i + 1] = self.contacts[i + 1], self.contacts[i]

    def append_contact(self, new_contact: Contact) -> None:
        if isinstance(new_contact, Contact): self.contacts.append(new_contact)
        else: print("Non-contact object can't be added to contact list.")

    def remove_contact(self, name: str) -> None:
        target_contact = self.search_contact(name)
        if target_contact != None: self.contacts.remove(target_contact)
        else: print("No contact with given name was found - unsuccessful removal.")