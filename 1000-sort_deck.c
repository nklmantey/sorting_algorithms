#include "deck.h"

#include <stdio.h>
void sort_suit(deck_node_t **deck);
void sort_val(deck_node_t **deck);
void swap(deck_node_t **deck, deck_node_t *card1, deck_node_t *card2);
int vcmp(const card_t *card1, const card_t *card2);
/**
 * sort_deck - sorts a 52 card deck
 * @deck: deck to sort
 *Authors: Lawrence Adams & Francesca Lynn Asiedu Asare
 *
 * Return: Always 0 (ok)
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL)
		return;
	sort_suit(deck);
	sort_val(deck);
}

/**
 * sort_suit - sorts a 52 card deck by suit
 * @deck: deck to sort
 */
void sort_suit(deck_node_t **deck)
{
	deck_node_t *forw, *tmp;

	for (forw = (*deck)->next; forw && forw->prev; forw = forw->next)
	{
		for (; forw && forw->prev && forw->card->kind <
			     forw->prev->card->kind; forw = forw->prev)
		{
			tmp = forw->prev;
			swap(deck, tmp, forw);
			forw = forw->next;
		}
	}
}

/**
 * sort_val - sorts a 52 card deck staticly by value
 * @deck: deck to sort
 */
void sort_val(deck_node_t **deck)
{
	deck_node_t *f, *tmp;

	for (f = (*deck)->next; f && f->prev; f = f->next)
	{
		for (; f && f->prev && vcmp(f->card, f->prev->card) &&
			     f->card->kind == f->prev->card->kind;
		     f = f->prev)
		{
			tmp = f->prev;
			swap(deck, tmp, f);
			f = f->next;
		}
	}
}
/**
 * swap - swaps 2 consecutive cards of a doubly linked list
 * Used in the insertion algorithm
 * @deck: Head node for the deck
 * @card1: The first card to swap
 * @card2: The second card to swap
 */
void swap(deck_node_t **deck, deck_node_t *card1, deck_node_t *card2)
{
	deck_node_t *prev, *next;

	prev = card1->prev;
	next = card2->next;

	if (prev != NULL)
		prev->next = card2;
	else
		*deck = card2;
	card1->prev = card2;
	card1->next = next;
	card2->prev = prev;
	card2->next = card1;
	if (next)
		next->prev = card1;
}

/**
 * vcmp - compares 2 card values
 * @card1: The first card to compare
 * @card2: The second card to compare
 *
 * Return: 1 if less than, 0 if greater or equal to
 */
int vcmp(const card_t *card1, const card_t *card2)
{
	char char1 = card1->value[0], char2 = card2->value[0];
	const char *ord[14] = {"Ac", "1", "2", "3", "4", "5", "6",
			       "7", "8", "9", "10", "Ja", "Qu", "Ki"};
	int idx1 = 0, idx2 = 0, i;

	if ((char1 >= 48 && char1 <= 57) && (char2 >= 49 &&
					     char2 <= 57))
	{
		if (card1->value[1] == '0')
			char1 = 58;
		if (card2->value[1] == '0')
			char2 = 58;
		return (char1 < char2);
	}
	else
	{
		for (i = 0; i < 14; i++)
		{
			if (card1->value[0] == ord[i][0] &&
			    card1->value[1] == ord[i][1])
				idx1 = i;
			if (card2->value[0] == ord[i][0] &&
			    card2->value[1] == ord[i][1])
				idx2 = i;
		}
		return (idx1 < idx2);
	}
}
